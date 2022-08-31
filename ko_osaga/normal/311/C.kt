import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of int
private fun readLongs() = readStrings().map { it.toLong() } // list of long
private fun readDoubles() = readStrings().map { it.toDouble() } // list of long

data class Gems(var pos : Long, var cost : Int, var index : Int) : Comparable<Gems> {
    override fun compareTo(other: Gems): Int = when{
        cost < other.cost || (cost == other.cost && index > other.index) -> 1
        cost > other.cost || (cost == other.cost && index < other.index) -> -1
        else -> 0
    }
}

data class Node(var dist : Long, var idx : Int) : Comparable<Node> {
    override fun compareTo(other: Node): Int = when{
        dist < other.dist -> -1
        dist > other.dist -> 1
        else -> 0
    }
}

fun main(){
    val fuck = readLongs()
    val n = fuck[1].toInt()
    val m = fuck[2].toInt()
    val k = fuck[3].toInt()
    var pts = Array(n) {
        val str = readLongs()
        Gems(str[0] - 1, str[1].toInt(), it)
    }
    var used = BooleanArray(n)
    var droga = mutableListOf<Long>()
    var pq = PriorityQueue<Gems>()
    var dist = LongArray(k) { 2e18.roundToLong() }
    fun repopulate(){
        dist.fill(2e18.roundToLong())
        dist[0] = 0
        var queue = PriorityQueue<Node>()
        queue.add(Node(0L, 0))
        while(!queue.isEmpty()){
            var x = queue.remove()
            if(dist[x.idx] != x.dist) continue
            for(j in droga){
                if(dist[((x.idx + j) % k).toInt()] > dist[x.idx] + j){
                    dist[((x.idx + j) % k).toInt()] = dist[x.idx] + j
                    queue.add(Node(dist[((x.idx + j) % k).toInt()], ((x.idx + j) % k).toInt()))
                }
            }
        }
        while(!pq.isEmpty()) pq.poll()
        for (i in 0 until n){
            if(!used[i] && dist[(pts[i].pos % k).toInt()] <= pts[i].pos){
                pq.add(pts[i].copy())
            }
        }
    }
    repopulate()
    repeat(m){
        val l = readLongs()
        when(l[0]){
            1L -> {
                droga.add(l[1])
                repopulate()
            }
            2L -> {
                var idx = (l[1] - 1).toInt()
                pts[idx].cost -= l[2].toInt()
                if(dist[(pts[idx].pos % k).toInt()] <= pts[idx].pos){
                    pq.add(pts[idx].copy())
                }
            }
            3L -> {
                var good = false
                while(!pq.isEmpty()){
                    var x = pq.poll()
                    if(x.cost == pts[x.index].cost && !used[x.index]){
                        println(x.cost)
                        good = true
                        used[x.index] = true
                        break
                    }
                }
                if(!good) println(0)
            }
        }
    }
}
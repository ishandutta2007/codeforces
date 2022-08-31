import java.util.*
import kotlin.collections.ArrayList
import kotlin.collections.HashSet

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(){
    val t = readInt()
    for(tt in 0..t-1){
        val (n, k) = readInts()
        var deg = IntArray(n)
        var g = Array<MutableList<Int>>(n, { i -> mutableListOf() })

        for(i in 1..n-1){
            var (u, v) = readInts()
            u--
            v--
            deg[u]++
            deg[v]++
            g[u].add(v)
            g[v].add(u)
        }
        if(n == 2){
            println("Yes")
            println(k)
            for(i in 0..k-1) print("${i + 1} ")
            println()
            continue
        }
        var root = -1
        for(i in 0..n-1) if(deg[i] > 1 && root == -1){
            root = i
        }
        var depth = IntArray(n)
        var leaves = ArrayList<Int>()
        var par = IntArray(n)
        fun dfs(s : Int, p : Int, d : Int) : Int {
            depth[s] = d
            par[s] = p
            g[s].forEach(){
                var v = it
                if(v != p){
                    dfs(v, s, d + 1)
                }
            }
            if(deg[s] == 1 && leaves.size < k){
                leaves.add(s)
            }
            return 0
        }

        dfs(root, -1, 0)
        if(leaves.size != k){
            println("No")
            continue
        }
//        println("${leaves}")
//        println(root)
//        depth.forEach { print("${it} ") }
//        println()
        val pq = PriorityQueue<Pair<Int,Int>>(compareBy {-it.first})
        var nodes = HashSet<Int>()
        leaves.forEach{
            pq.add(Pair<Int, Int>(depth[it], it))
            nodes.add(it)
        }
        while(pq.size > 1){
            var v = pq.poll();
            var p = par[v.second]
            if(p != -1 && !nodes.contains(p)){
                nodes.add(p)
                pq.add(Pair<Int, Int>(depth[p], p))
            }
        }
        nodes.add(pq.poll().second)

        println("Yes")
        println(nodes.size)
        nodes.forEach{
            print("${it+1} ")
        }
        println()
    }
}
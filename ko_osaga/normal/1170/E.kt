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
    var (n, m) = readInts()
    var arr = readInts().toIntArray()
    var psum = IntArray(n + 1){ 0 }
    for (i in 1..n){
        psum[i] = psum[i-1] + arr[i - 1]
    }
    var q = readInt()
    repeat(q){
        var qr = readInts().toIntArray()
        qr[0] = 0
        var ptr = 0
        fun prog(x : Int){
            var y = x + psum[ptr]
            var idx = psum.binarySearch(y)
            if(idx >= 0) ptr = idx + 1
            else{
                idx = -idx - 1
                ptr = idx
            }
            ptr--
        }
        for (i in 1 until qr.size){
            var needy = qr[i] - qr[i-1] - 1
            prog(needy)
        }
        var needy = m - qr[qr.size - 1]
        prog(needy)
        if(ptr == n) println("YES")
        else println("NO")
    }
}
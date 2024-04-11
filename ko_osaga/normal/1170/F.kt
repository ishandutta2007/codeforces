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
    var (n, m, k) = readInts()
    var arr = readInts().toIntArray().sorted()
    var psum = LongArray(n + 1) { 0L }
    for (i in 1..n){
        psum[i] = psum[i-1] + arr[i-1]
    }
    fun getsum(s : Int, e : Int) : Long{
        return arr[e].toLong() * (e - s + 1) - (psum[e + 1] - psum[s])
    }
    var ptr = 0
    var dap = 1e18.roundToLong()
    for (i in 0..(n-m)){
        var nxtptr = (2 * i + m - 1) / 2
        while(ptr < nxtptr && getsum(i, ptr + 1) <= k) ptr++
        if(ptr == nxtptr){
            var leftsum = getsum(i, ptr) // [i, ptr]
            var rightsum = psum[i + m] - psum[ptr + 1] - arr[ptr].toLong() * (i + m - ptr - 1) // [ptr + 1, i + m - 1]
            dap = min(dap, leftsum + rightsum)
        }
        else{
            var slack1 = (k - getsum(i, ptr)) / (ptr - i + 1)
            var slack2 = slack1 + 1
            var leftsum1 = getsum(i, ptr) + slack1 * (ptr - i + 1).toLong()
            var rightsum1 =
                psum[i + m] - psum[ptr + 1] - (arr[ptr].toLong() + slack1) * (i + m - ptr - 1)
            dap = min(dap, leftsum1 + rightsum1)
            // [ptr + 1, i + m - 1]
        }
    }
    println(dap)
}
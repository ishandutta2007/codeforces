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
    var n = readInt()
    var arr = readInts().toIntArray()
    var x = -1e9.toInt()
    var y = -1e9.toInt()
    var ret = 0
    for (i in 0 until n){
        if(y > arr[i]){
            ret++
        }
        if(x < arr[i]){
            y = x
            x = arr[i]
        }
        else if(y < arr[i]){
            y = arr[i]
        }
    }
    println(ret)
}
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
    var t = readInt()
    repeat(t){
        var s = readLn()
        var t = readLn()
        var ptr = 0
        var good = true
        for (i in t){
            if(ptr == s.length){
                good = false
                break
            }
            if(i == '-'){
                if(s[ptr] == '-'){
                    ptr++
                }
                else{
                    good = false
                    break
                }
            }
            else{
                if(s[ptr] == '-' && (ptr + 1 < s.length && s[ptr + 1] == '-')){
                    ptr += 2
                }
                else if(s[ptr] == '+'){
                    ptr++;
                }
                else{
                    good = false
                    break
                }
            }
        }
        if(ptr != s.length) good = false
        if(good) println("YES");
        else println("NO")
    }
}
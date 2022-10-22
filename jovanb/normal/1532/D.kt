import java.util.*
import java.util.Arrays.sort
import kotlin.math.*

fun readLn() = readLine()!! // string line
fun readInt() = readLn().toInt() // single int
fun readStrings() = readLn().split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints
fun readLong() = readLn().toLong() // single long
fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main() {
    var n = readInt()
    var a = readInts().toIntArray()
    sort(a)
    var res = 0L
    for(i in 0..n-1 step 2){
        res += a[i+1] - a[i]
    }
    println(res)
}
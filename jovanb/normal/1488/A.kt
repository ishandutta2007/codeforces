import java.util.*
import kotlin.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readString() = readLn().toString()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    var t = readInt()
    for(tt in 1..t){
        var (x, y) = readLongs()
        var tr = 1L
        for (i in 1..9) tr *= 10
        var k = 0L
        var turns = 0L
        for (p in 9 downTo 0) {
            while (k + tr * x <= y) {
                turns++
                k += tr * x
            }
            tr /= 10
        }
        turns += y - k
        println(turns)
    }
}
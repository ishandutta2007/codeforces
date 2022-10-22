import java.util.*
import kotlin.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    var t = readInt()
    while(t > 0){
        t--
        var (n, k) = readInts()
        var res = 0
        for(i in 1..n){
            var (l, r) = readInts()
            if(k >= l) res = max(res, r - k + 1);
        }
        println(res)
    }
}
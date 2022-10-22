import java.util.*
import kotlin.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readStrings().map { it.toLong() }

fun solve(){
    var (n, x, y) = readInts()
    if(x > y){
        x = y.also {y = x}
    }
    var res = 2*n
    for(spl in x until y){
        res = min(res, max(2*spl-1-max(spl-x, x-1), 2*(n-spl)-1-max(y-1-spl, n-y)))
    }
    println(res-1)
}

fun main() {
    var t = readInt()
    while(t > 0){
        t--
        solve()
    }
}
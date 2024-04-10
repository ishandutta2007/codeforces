import java.util.*
import kotlin.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readStrings().map { it.toLong() }

fun solve(){
    var (n, k) = readInts()
    var s = readLn()
    var res = 0
    var st = 0
    for(i in 0 until n){
        if(s[i] == '(') st++
        else{
            if(st == 1) res++
            else if(k > 0){
                k--
                res++
            }
            st--
        }
    }
    println(res)
}

fun main() {
    var t = readInt()
    while(t > 0){
        t--
        solve()
    }
}
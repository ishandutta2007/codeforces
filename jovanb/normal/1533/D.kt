import java.util.*
import kotlin.collections.HashMap
import kotlin.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readStrings().map { it.toLong() }

fun solve(){
    var (n, m) = readInts()
    var ima = mutableMapOf<String, Int>()
    var strings = arrayListOf<String>()
    for(i in 0 until n){
        strings.add(readLn())
        ima[strings[i]] = 0
    }
    for(i in 0 until n){
        ima[strings[i]] = ima[strings[i]]!! + 1
    }
    var q = readInt()
    while(q > 0){
        q--
        var s = readLn()
        var bio = mutableMapOf<String, Int>()
        var res = 0
        for(skip in 0 until m+1){
            var k = ""
            for(i in 0 until skip) k += s[i]
            for(i in skip+1 until m+1) k += s[i]
            bio[k] = 0
        }
        for(skip in 0 until m+1){
            var k = ""
            for(i in 0 until skip) k += s[i]
            for(i in skip+1 until m+1) k += s[i]
            if(bio[k]!! == 1) continue;
            bio[k] = 1
            if(ima[k] != null) res += ima[k]!!
        }
        println(res)
    }
}

fun main() {
    var t = 1
    while(t > 0){
        t--
        solve()
    }
}
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
    var s = readLn()
    var n = s.length
    var pref1 = arrayListOf<Int>()
    var pref0 = arrayListOf<Int>()
    var koji0 = arrayListOf<Int>()
    var koji1 = arrayListOf<Int>()
    var gde0 = arrayListOf<Int>()
    var gde1 = arrayListOf<Int>()
    for(i in 0..n) pref1.add(0)
    for(i in 0..n) pref0.add(0)
    for(i in 0..3*n) gde0.add(n+1)
    for(i in 0..3*n) gde1.add(n+1)
    for(i in 0..n) koji0.add(0)
    for(i in 0..n) koji1.add(0)
    var bilo0 = 0
    var bilo1 = 0
    for(i in 1..n){
        pref1[i] = pref1[i-1]
        pref0[i] = pref0[i-1]
        koji0[i] = bilo0 + 1
        koji1[i] = bilo1 + 1
        if(s[i-1] == '0'){
            pref0[i]++
            bilo0++
            gde0[bilo0] = i
        }
        else {
            pref1[i]++
            bilo1++
            gde1[bilo1] = i
        }
    }
    for(len in 1..n){
        var tren = 1
        var cnt = 0
        while(tren <= n){
           // println(tren)
            var pos1 = gde1[koji1[tren] + len]
            var pos0 = gde0[koji0[tren] + len]
            //println(pos1)
            //println(pos0)
            tren = max(pos1, pos0)
            cnt++
        }
        print(cnt)
        print(" ")
    }
}

fun main() {
    var t = 1
    while(t > 0){
        t--
        solve()
    }
}
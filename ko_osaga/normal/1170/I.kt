import java.util.*
import java.util.Collections.swap
import kotlin.math.*
import kotlin.system.exitProcess
import kotlin.reflect.jvm.internal.ReflectProperties.lazy
import kotlin.reflect.jvm.internal.ReflectProperties.lazy





private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of int
private fun readLongs() = readStrings().map { it.toLong() } // list of long
private fun readDoubles() = readStrings().map { it.toDouble() } // list of long
val mod = 998244353
var pwr = Array(800005) { 1 }

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

val MAXT = 2100000
var tree = Array(MAXT){ 0L }
var lazy = Array(MAXT){ 0 }

fun lazydown(P: Int){
    tree[2 * P] = tree[2 * P] * pwr[lazy[P]] % mod
    lazy[2 * P] += lazy[P]
    tree[2 * P + 1] = tree[2 * P + 1] * pwr[lazy[P]] % mod
    lazy[2 * P + 1] += lazy[P]
    lazy[P] = 0
}

fun pl(SS: Int, SE: Int, X: Int, P: Int, V: Int) {
    if (SE < X || X < SS) return
    if (SS == SE) {
        tree[P] = (tree[P] + V) % mod
        return
    }
    lazydown(P)
    val mid = (SS + SE) / 2
    pl(SS, mid, X, 2 * P, V)
    pl(mid + 1, SE, X, 2 * P + 1, V)
    tree[P] = (tree[2 * P] + tree[2 * P + 1]) % mod
}

fun pl(X: Int, V: Int) {
    pl(0, 800004, X, 1, V)
}

fun ml(SS: Int, SE: Int, S: Int, E: Int, P: Int, V: Int) {
    if (S <= SS && SE <= E) {
        tree[P] = tree[P] * pwr[V] % mod
        lazy[P] += V
        return
    }
    if (SE < S || E < SS) return
    lazydown(P)
    val mid = (SS + SE) / 2
    ml(SS, mid, S, E, 2 * P, V)
    ml(mid + 1, SE, S, E, 2 * P + 1, V)
    tree[P] = (tree[2 * P] + tree[2 * P + 1]) % mod
}

fun ml(S: Int, E: Int, V: Int) {
    ml(0, 800004, S, E, 1, V)
}

fun query(SS: Int, SE: Int, S: Int, E: Int, P: Int): Int {
    if (S <= SS && SE <= E) return tree[P].toInt()
    if (SE < S || E < SS) return 0
    lazydown(P)
    val mid = (SS + SE) / 2
    return (query(SS, mid, S, E, 2 * P) + query(mid + 1, SE, S, E, 2 * P + 1)) % mod
}

fun query(S: Int, E: Int): Int {
    return query(0, 800004, S, E, 1)
}

fun main(){
    var dx = Array(800005) { 0 }
    var mp = Array(800005) { 0 }
    for(i in 1..800004) pwr[i] = pwr[i-1] * 2 % mod
    var cnt = 0
    var n = readInt()
    var crd = mutableListOf<Int>()
    var intv = Array(n){
        var (s, e) = readInts()
        crd.add(s)
        crd.add(e)
        Pair<Int, Int> (s, e)
    }
    crd = crd.sorted().toList().distinct().toMutableList()
    for (i in 0 until n){
        var s = crd.binarySearch(intv[i].first)
        var e = crd.binarySearch(intv[i].second)
        intv[i] = Pair<Int, Int>(s * 2, e * 2)
        dx[2 * s]++
        dx[2 * e + 1]--
    }
    for(i in 1..800004) dx[i] += dx[i-1]
    for(i in 0..800004){
        if(dx[i] > 0){
            cnt++
            mp[i] = cnt
        }
    }
    dx.fill(0)
    for (i in 0 until n){
        var s = mp[intv[i].first]
        var e = mp[intv[i].second]
        intv[i] = Pair<Int, Int>(s, e)
        dx[s]++
    }
    for(i in 800003 downTo 0) dx[i] += dx[i+1]
    intv.sortBy { it.second }
    var left = 0
    var ptr = 0
    var dp = Array(800005) { 0 }
    dp[0] = 1
    pl(0, 1)
    var ret = 0L
    for(i in 1..(cnt + 1)){
        dp[i] = pwr[ptr]
        var sum = 0
        if(i > 1) sum = query(1, i - 1)
        dp[i] += mod - sum
        dp[i] %= mod
        pl(i, dp[i])
        while(ptr < n && intv[ptr].second == i){
            ml(0, intv[ptr].first - 1, 1)
            ptr++
        }
    }
    println(dp[cnt + 1] % mod)
}
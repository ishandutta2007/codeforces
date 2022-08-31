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

val mod = 95542721
val MAXT = 270000
val tree = Array(MAXT) { IntArray(48) }
val lazy = Array(MAXT) { 0 }
fun f(x : Int) = (((1L * x * x % mod) * x) % mod).toInt()

fun init(s : Int, e : Int, p : Int, arr : IntArray){
    if(s == e) {
        var cur = arr[s] % mod
        tree[p][0] = cur
        for (i in 1..47) {
            cur = f(cur)
            tree[p][i] = cur
        }
        cur = f(cur)
        assert(cur == arr[s])
        return
    }
    var m = (s + e) / 2
    init(s, m, 2*p, arr)
    init(m + 1, e, 2*p+1, arr)
    for (i in 0..47){
        tree[p][i] = (tree[2*p][i] + tree[2*p+1][i]) % mod
    }
}

fun update(s : Int, e : Int, ps : Int, pe : Int, p : Int){
    if(e < ps || pe < s) return
    if(s <= ps && pe <= e){
        tree[p] = tree[p].sliceArray(1 until 48) + tree[p].sliceArray(0 until 1)
        lazy[p] = (lazy[p] + 1) % 48
        return
    }
    lazydown(p)
    var pm = (ps + pe) / 2;
    update(s, e, ps, pm, 2*p)
    update(s, e, pm+1, pe, 2*p+1)
    for (i in 0..47){
        tree[p][i] = (tree[2*p][i] + tree[2*p+1][i]) % mod
    }
}

fun lazydown(p : Int){
    lazy[2*p] += lazy[p]
    lazy[2*p+1] += lazy[p]
    lazy[2*p] %= 48
    lazy[2*p+1] %= 48
    tree[2*p] = tree[2*p].sliceArray(lazy[p] until 48) + tree[2*p].sliceArray(0 until lazy[p])
    tree[2*p+1] = tree[2*p+1].sliceArray(lazy[p] until 48) + tree[2*p+1].sliceArray(0 until lazy[p])
    lazy[p] = 0
}

fun query(s : Int, e : Int, ps : Int, pe : Int, p : Int):Int{
    if(e < ps || pe < s) return 0
    if(s <= ps && pe <= e) return tree[p][0]
    lazydown(p)
    var pm = (ps + pe) / 2
    return (query(s, e, ps, pm, 2*p) + query(s, e, pm+1, pe, 2*p+1)) % mod
}

fun main(){
    var n = readInt()
    var arr = readInts().toIntArray()
    init(0, n - 1, 1, arr)
    var q = readInt()
    repeat(q){
        val (t, l, r) = readInts()
        if(t == 1){
            println(query(l - 1, r - 1, 0, n - 1, 1))
        }
        if(t == 2){
            update(l - 1, r - 1, 0, n - 1, 1)
        }
    }
}
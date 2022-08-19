import java.util.*
import java.util.Collections.swap
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

val MAXN = 444444
var n = 0
var m = 0
var st = Array(MAXN) { 0 }
var back = Array(MAXN) { 0 }
var link = Array(MAXN) { 0 }
var visvis = Array(MAXN) { 0 }
var v = Array(MAXN) { 0 }
var nex = Array(MAXN) { 0 }
var sz = 0
var cyc = mutableListOf<Int>()

fun add_edge(s : Int, e : Int){
    sz++;
    link[sz] = e; back[sz] = st[s]; st[s] = sz; nex[back[sz]] = sz;
    sz++;
    link[sz] = s; back[sz] = st[e]; st[e] = sz; nex[back[sz]] = sz;
}

fun f(x : Int){
    var s = Stack<Int>()
    s.push(x)
    while(!s.isEmpty()){
        var x = s.peek()
        visvis[x] = 1
        var p = st[x]
        var pushed = 0
        while(p != 0){
            val pos = link[p]
            val q = (p + 1) / 2
            var r = p
            if (p % 2 == 1) r++
            else r--
            p = back[p]
            st[x] = p
            if (r === st[pos]) {
                st[pos] = back[r]
            } else {
                val s = nex[r]
                back[s] = back[r]
                nex[back[r]] = s
            }
            if (v[q] == 0) {
                v[q] = 1
                s.push(pos)
                pushed++
                break
            }
        }
        if(pushed == 0) s.pop();
        if(pushed == 0) cyc.add(x)
    }
}

var vis = Array(MAXN) { 0 }
var temp = Stack<Int>()
var deg = Array(MAXN) { 0 }

fun main(){
    var (n, m) = readInts()
    var ans = mutableListOf<MutableList<Int>>()
    for(i in 1..m){
        var (s, e) = readInts()
        if(s == e){
            var lis = mutableListOf(s)
            ans.add(lis)
            continue
        }
        add_edge(s, e)
        deg[s]++
        deg[e]++
    }
    for(i in 1..n){
        if(deg[i] % 2 == 1){
            println("NO")
            return
        }
    }

    for(i in 1..n) {
        if (visvis[i] == 1 || deg[i] == 0) continue
        f(i)
        temp.clear()
        var curlis = mutableListOf<Int>()
        for (i in 0 until cyc.size) {
            temp.add(cyc[i])
            if (vis[cyc[i]] != 0) {
                curlis.add(temp.pop())
                while (temp.peek() != cyc[i]) {
                    curlis.add(temp.peek())
                    vis[temp.peek()] = 0
                    temp.pop()
                    if (temp.peek() == cyc[i]) {
                        ans.add(curlis)
                        curlis = mutableListOf<Int>()
                    }
                }
            } else vis[cyc[i]] = 1
        }
        cyc.clear()
    }
    println("YES")
    println(ans.size)
    for(i in ans){
        i.add(i[0])
        var dap = i.joinToString(" ")
        println((i.size).toString()+ " " + dap)
    }
}
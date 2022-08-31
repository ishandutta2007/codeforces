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

fun report(a : MutableList<Int>){
    var arr = a.toIntArray().sorted()
    if(arr.size == 1){
        println(1)
        println(arr[0])
        return
    }
    var ans = mutableListOf<Int>()
    var n = arr.size / 2
    if(arr.size % 2 == 1 && (arr[0] == arr[n] || arr[n] == arr[2*n])){
        if(arr[n] == arr[0]){
            arr = arr.reversed()
        }
    }
    for(i in n..(arr.size - 1)){
        ans.add(arr[i])
        if(i < 2 * n) ans.add(arr[i - n])
    }
    println(ans.size)
    println(ans.joinToString(" "))
}

fun main(){
    var t = readInt()
    for(it in 0..(t-1)){
        var n = readInt()
        var arr = readInts().toIntArray().sorted().toIntArray()
        var s = 1
        var e = n
        fun trial(x : Int) : Boolean{
            if(x == 1) return true
            var i = 0
            var ret = 0
            while(i < n){
                var e = i
                while(e < n && arr[i] == arr[e]) e++
                ret += min(x / 2, (e - i))
                i = e
            }
            if(ret >= x) return true
            if(x % 2 == 1){
                i = 0
                ret = 0
                while(i < n){
                    var e = i
                    while(e < n && arr[i] == arr[e]) e++
                    if(e - i >= x / 2 + 1){
                        if(ret >= x / 2) return true
                    }
                    ret += min(x / 2, (e - i))
                    i = e
                }
                i = 0
                ret = 0
                while(i < n){
                    var e = i
                    while(e < n && arr[n-1-i] == arr[n-1-e]) e++
                    if(e - i >= x / 2 + 1){
                        if(ret >= x / 2) return true
                    }
                    ret += min(x / 2, (e - i))
                    i = e
                }
            }
            return false
        }
        while(s != e){
            var m = (s + e + 1) / 2
            if(trial(m)) s = m
            else e = m - 1
        }
        if(s == 1){
            report(mutableListOf(arr[0]))
            continue
        }
        var x = s
        var i = 0
        var ret = mutableListOf<Int>()
        while(i < n){
            var e = i
            while(e < n && arr[i] == arr[e]) e++
            for(j in 0 until min(x / 2, e - i)) {
                ret.add(arr[i])
            }
            i = e
        }
        if(ret.size >= x){
            report(ret.subList(0, x))
            continue
        }
        if(x % 2 == 1) {
            i = 0
            ret.clear()
            var good = false
            while (i < n) {
                var e = i
                while (e < n && arr[i] == arr[e]) e++
                if (e - i >= x / 2 + 1) {
                    if (ret.size >= x / 2) {
                        ret = ret.subList(0, x / 2)
                        for (j in 0..(x / 2)) {
                            ret.add(arr[i])
                        }
                        report(ret)
                        good = true
                        break
                    }
                }
                for(j in 0 until min(x / 2, e - i)) {
                    ret.add(arr[i])
                }
                i = e
            }
            if(good){
                continue
            }
            for (i in 0..n-1){
                if(i < n - 1 - i){ // why swap doesnt work..
                    var t = arr[i]
                    arr[i] = arr[n-1-i]
                    arr[n-1-i] = t
                }
            }
            i = 0
            ret.clear()
            while (i < n) {
                var e = i
                while (e < n && arr[i] == arr[e]) e++
                if (e - i >= x / 2 + 1) {
                    if (ret.size >= x / 2) {
                        ret = ret.subList(0, x / 2)
                        for (j in 0..(x / 2)) {
                            ret.add(arr[i])
                        }
                        report(ret)
                        good = true
                        break
                    }
                }
                for(j in 0 until min(x / 2, e - i)) {
                    ret.add(arr[i])
                }
                i = e
            }
            if(good) continue
        }
        assert(false)
    }
}
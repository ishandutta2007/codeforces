import java.lang.Long.min
import java.math.BigInteger
import java.util.*
import kotlin.collections.ArrayList

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(){
    val (m, k) = readLongs()
    var possibilities = ArrayList<IntArray>()
    var curr = IntArray(10)
    fun rec(prod : Long, i : Int){
        if(i == 10){
            if(prod != m) return
            possibilities.add(curr.copyOf())
            return
        }
        var j = 0
        var z = prod
        while(z <= m){
            curr[i] = j
            rec(z, i + 1)
            z *= i
            j ++
        }
    }
    rec(1, 2)

    if(possibilities.isEmpty()){
        println(-1)
        return
    }

    var fact = Array<BigInteger>(3000){i -> BigInteger("1")}
    for(i in 1..2999) fact[i] = fact[i - 1].multiply(BigInteger.valueOf(i.toLong()))
    val INF = 1e16.toLong()

    val K = BigInteger.valueOf(k)
    fun count(l : Int, possibility : IntArray) : BigInteger{
        var is_small_prime = true
        var num = 0
        var sm = 0
        for(i in 2..9){
            sm += possibility[i]
            if(possibility[i] < 0) return BigInteger.ZERO
            if(possibility[i] == 1) {
                if(num == 0) num = 1
                else is_small_prime = false
            }
            if(possibility[i] > 1) is_small_prime = false
        }
        var ret = if(is_small_prime) BigInteger.ONE else fact[l]
        for(i in 2..9){
            if(is_small_prime){
                if(possibility[i] == 1) ret = ret.multiply(BigInteger.valueOf(l.toLong()))
            }else{
                ret = ret.divide(fact[possibility[i]])
            }
        }
        if(sm > l) return BigInteger.ZERO
        if(!is_small_prime) ret = ret.divide(fact[l - sm])
        return ret
    }

    fun countAll(l : Int) : BigInteger{
        var ret : BigInteger = BigInteger.ZERO
        for(possibility in possibilities) ret += count(l, possibility)
        return ret
    }

    var l = 1
    var tot : BigInteger = BigInteger.ZERO
    while(tot < K){
        tot += countAll(l)
        l += 1
    }
    l--
    tot -= countAll(l)
    var answer = IntArray(l)
    for(i in 0..l-1){
        var d = 1
        while(d <= 9){
            var _tot = tot
            for(p in possibilities){
                var q = p.copyOf()
                if(d != 1) q[d]--
                _tot += count(l - 1 - i, q)
            }
            if(_tot >= K){
                for(p in possibilities){
                    p[d]--
                }
                answer[i] = d
                break
            }
            tot = _tot
            d++
        }
    }
    for(i in 0..l-1) print(answer[i])
    println()
}
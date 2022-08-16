import java.lang.AssertionError
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun main() {
    repeat(readInt()){
        val n = readInt()
        var mn = 0
        var mx = 1000000
        for(i in 1..n){
            val inp = readStrings()
            val s = inp[0]
            val t = inp[1]
            val r = inp[2].toInt()
            var l = 0
            for(i in 0..minOf(s.length-1,t.length-1)){
                if(s[s.length - 1 - i] == t[t.length - 1 - i]){
                    l+=1
                } else break
            }
            if(r==0){
                mn = maxOf(mn, l + 1)
            } else{
                mx = minOf(mx, l)
            }
        }
        println(maxOf(0, mx - mn + 1))
        if(mx >= mn)
            for(i in mn..mx) print(i.toString() + " ")
        println()
    }
}
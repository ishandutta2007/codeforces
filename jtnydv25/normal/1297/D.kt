private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(){
    val t = readInt();
    for(tt in 0..t-1){
        val (n, k) = readInts();
        val a = readInts();
        var order = IntArray(n) {it}.sortedBy {-a[it]}
        var lo = 0
        var hi = a[order[0]] + k
        while(lo < hi){
            var mid = ((lo + 0L + hi) / 2).toInt()
            // mid
            var ok = true
            var rem = k
            var old = mid
            for(i in 0..n-1){
                // a[order[i]] + x<= old
                if(a[order[i]] > old){
                    ok = false;
                    break;
                }
                var toAdd = Integer.min(old - a[order[i]], rem)
                rem -= toAdd
                old = a[order[i]] + toAdd - 1
            }
            if(rem > 0) ok = false
            if(ok) hi = mid
            else lo = mid + 1
        }
        var d = IntArray(n);
        var mid = lo
        var rem = k
        var old = mid
        for(i in 0..n-1){
            var toAdd = Integer.min(old - a[order[i]], rem)
            d[order[i]] = toAdd
            rem -= toAdd
            old = a[order[i]] + toAdd - 1
        }
        for(i in 0..n-1) print("${d[i]} ")
        println()
    }
}
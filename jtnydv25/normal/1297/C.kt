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
        val n = readInt()
        val a = readInts()
        var order = IntArray(n) {it}.sortedBy {-a[it]}
        var sum : Long = 0;
        a.forEach{sum +=it;}
        var neg_pos = n;
        for(i in 0..n-1){
            if(a[order[i]] < 0){
                neg_pos = i;
                break;
            }
        }
        var found = CharArray(n){'1'}

        if(neg_pos==n){
            while(true){
                neg_pos--;
                if(a[order[neg_pos]] > 0){
                    found[order[neg_pos]] = '0'
                    sum -= a[order[neg_pos]];
                    break;
                    neg_pos--;
                }
            }
        } else{
            var sum2 = sum
            for(j in neg_pos+1..n-1){
                found[order[j]] = '0'
                sum2 -= a[order[j]];
            }
            var sum3 = sum2 - a[order[neg_pos]]
            var pos = neg_pos - 1
            while(pos >= 0 && a[order[pos]] <= 0) pos--;
            sum3 -= a[order[pos]]
            if(sum3 > sum2){
                found[order[pos]] = '0'
                found[order[neg_pos]] = '0'
                sum = sum3
            } else sum = sum2

        }
        println(sum);
        println(found.joinToString(""));
    }
}
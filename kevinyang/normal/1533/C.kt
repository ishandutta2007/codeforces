private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
fun main(args: Array<String>) {
    var t = readInt();
    repeat(t){
    	var (n,k) = readInts();
    	var s = readLn();
    	var total = 0;
    	for(i in 0..n-1){
    		if(s[i]=='1')total++;
    	}
    	var arr = ArrayList<Int>()
    	for(i in 1..n){
    		arr.add(i);
    	}
    	var cnt = 0
    	var cur = 0
    	for(tt in 0..n-1){
    		if(total==0)break;
    		var value = arr.get(cur);
    		cnt++;
    		if(s[value-1]=='1')total--;
    		if(total==0)break;
    		arr.removeAt(cur);
    		cur+=k-1;
    		cur%=arr.size;
    	}
    	println(cnt);
    }
}
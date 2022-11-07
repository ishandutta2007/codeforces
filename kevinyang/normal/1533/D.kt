private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
fun main(args: Array<String>) {
    var (n,m) = readInts();
    var hm = hashMapOf<String, Int>();
    for(i in 0..n-1){
    	var s = readLn();
    	hm[s] = 1;
    }
    var q = readInt();
    for(qq in 0..q-1){
    	var s = readLn();
    	var ans = 0
    	var hm2 = hashMapOf<String,Int>()
    	for(i in 0..m){
    		var ns = s.substring(0,i) + s.substring(i+1);
    		if(hm.containsKey(ns)&&!hm2.containsKey(ns)){
    			ans++;
    		}
    		hm2[ns] = 1;
    	}
    	println(ans);
    }
}
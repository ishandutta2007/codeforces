private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
fun main(args: Array<String>) {
	var n = readInt();
	var arr2 = readInts();
	var arr = IntArray(n+1);
	var vis = BooleanArray(n+1);
	var vals = IntArray(n+1);
	for(i in 1..n){
		arr[i] = arr2[i-1];
	}
	var ans = 0;
	for(t in 0..n-1){
		var mx = 0;
		var ind = 0;
		for(i in 1..n){
			if(vis[i]==true)continue;
			if(mx<arr[i]){
				mx = arr[i];
				ind = i;
			}
		}
		vals[t+1] = ind;
		vis[ind] = true;
		ans+=1+mx*t;
	}
	println(ans);
	for(i in 1..n){
		print(vals[i]);
		print(" ");
	}
}
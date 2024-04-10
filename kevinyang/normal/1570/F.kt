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
	val arr = Array(n+1) {IntArray(m+1)};
	val arr2 = Array(n+1) {IntArray(m+1)};
	for(i in 1..n){
		var vals = readInts();
		for(j in 1..m){
			arr2[i][j] = vals[j-1];
		}
	}
	val x = mutableListOf<Int>();
	val y = mutableListOf<Int>();
	for(i in 1..n-1){
		for(j in 1..m-1){
			if(arr2[i][j]==1&&arr2[i+1][j]==1&&arr2[i][j+1]==1&&arr2[i+1][j+1]==1){
				arr[i][j] = 1;
				arr[i+1][j] = 1;
				arr[i][j+1] = 1;
				arr[i+1][j+1] = 1;
				x.add(i);
				y.add(j);
			}
		}
	}
	var f = true;
	for(i in 1..n){
		for(j in 1..m){
			if(arr[i][j]!=arr2[i][j])f = false;
		}
	}
	if(!f){
		println(-1);
	}
	else{
		println(x.count());
		for(i in 0..x.count()-1){
			print(x.elementAt(i));
			print(" ");
			println(y.elementAt(i));
		}
	}
}
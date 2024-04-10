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
		var s = readLn();
		var n = s.length;
		var vis = BooleanArray(n);
		var vis2 = BooleanArray(n);
		if(true){
			var f = false;
			for(i in 0..n-1){
				if(s[i]=='1')f = true;
				if(f&&s[i]=='0')vis[i] = true;
			}
		}
		if(true){
			var f = false;
			for(i in n-1 downTo 0){
				if(s[i]=='1')f = true;
				if(f&&s[i]=='0')vis2[i] = true;
			}
		}
		var cnt = 0;
		for(i in 0..n-1){
			//print(vis[i]);
			//print(" ");
			if(vis[i]&&vis2[i])cnt++;
		}
		println(cnt);
	}
}
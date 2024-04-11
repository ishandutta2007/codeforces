private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var t = readInt()
    while (t-- > 0) {
        var (n, m) = readInts()
        
        var mx = ArrayList<Int>();
        var u = ArrayList<Int>();
        var v = ArrayList<Int>();
        var s = ArrayList<Int>();
        
        for (i in 1..n)
            mx.add(0);
        for (i in 1..m)
        {
            var (x, y, z) = readInts();
            u.add(x);
            v.add(y);
            s.add(z);
            
            if (z > mx[x-1])
                mx[x-1]=z;
            if (z > mx[y-1])
                mx[y-1]=z;
        }
        
        var ok = true;
        for (i in 0..m-1)
        {
            var l = mx[u[i]-1];
            var r = mx[v[i]-1];
            var mid = s[i];
            if (mid != l)
            if (mid != r)
            ok = false;
        }
        
        if (!ok)
            println("NO");
        else 
        {    println("YES");
        for (i in 1..n)
        {
            print(mx[i-1]);
            print(' ');
        }
        }
        
        println();
    }
}
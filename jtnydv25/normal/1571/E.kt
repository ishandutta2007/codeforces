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
        val s = readLn()
        val t = readLn()
        val graph = Array(n){ArrayList<Int>()}
        val fixed = Array(n){0}
        val init = Array(n){0}
        for(i in 0..n-1) init[i] = if(s[i]=='(') 1 else 2
        for(i in 0..n-4){
            if(t[i] == '1'){
                fixed[i] = 1
                fixed[i + 3] = 2
                graph[i + 1].add(i + 2)
                graph[i + 2].add(i + 1)
            }
        }
        var comp = ArrayList<Int>()
        val color = Array(n){0}
        var is_fixed = false
        var error = false
        fun dfs(i: Int, c: Int){
            color[i] = c
            comp.add(i)
            if(error) return
            if(fixed[i] != 0){
                if(c != fixed[i]) {
                    if (is_fixed) {
                        error = true
                        return
                    }
                    for(j in comp) color[j] = 3 - color[j]
                }
                is_fixed = true
            }
            for(j in graph[i]){
                if(color[j]==0){
                    dfs(j, 3 - color[i])
                } else if(color[j] != 3 - color[i]){
                    error = true
                    return
                }
            }
        }
        var cost = 0
        for(i in 0..n-1) if(color[i] == 0){
            is_fixed = false
            comp.clear()
            dfs(i, 1)
            if(error) break
            var c = 0
            for(j in comp) if(init[j] != color[j]) c += 1
            if(is_fixed){
                cost += c
                continue
            }
            var c2 = 0
            for(j in comp) if(init[j] == color[j]) c2 += 1
            cost += minOf(c, c2)
        }
        if(error){
            println(-1)
        } else println(cost)
    }
}
//And after happily lived ever they
//And they lived happily ever after
fun main(){
    var a = readLine()!!.toInt()
    var b = 0
    if((a shr 0) and 1 == 1) b += 1 shl 4
    if((a shr 1) and 1 == 1) b += 1 shl 1
    if((a shr 2) and 1 == 1) b += 1 shl 3
    if((a shr 3) and 1 == 1) b += 1 shl 2
    if((a shr 4) and 1 == 1) b += 1 shl 0
    if((a shr 5) and 1 == 1) b += 1 shl 5
    print(b)
}
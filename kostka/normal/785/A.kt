fun main(args: Array<String>) {
  val n = readLine()!!.toInt()
  var ret = 0
  for(i in 1..n) {
    val obj = readLine()
    when(obj) {
      "Tetrahedron"  -> ret += 4
      "Cube"         -> ret += 6
      "Octahedron"   -> ret += 8
      "Dodecahedron" -> ret += 12
      "Icosahedron"  -> ret += 20
    }
  }
  println(ret)
}
fun transform(color: String?) : String? {
  when(color) {
    "purple" -> return "Power"
    "green"  -> return "Time"
    "blue"   -> return "Space"
    "orange" -> return "Soul"
    "red"    -> return "Reality"
    "yellow" -> return "Mind"
  }
  return null
}

fun main(args: Array<String>) {
  val n = readLine()!!.toInt()
  val seen : MutableSet<String?> = mutableSetOf()
  for(i in 1..n) {
    seen.add(transform(readLine()))
  }
  val all = setOf("Power", "Time", "Space", "Soul", "Reality", "Mind")
  println(6 - n)
  for(ele in all) {
    if(ele !in seen) println(ele)
  }
}
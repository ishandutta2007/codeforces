import kotlin.math.*
import java.util.*
import java.math.*

fun main(args : Array<String>) = with(Scanner(System.`in`)) {
	var cnt = 0
	for (i in 0..9){
		println(i)
		var s = nextLine().toCharArray().filter{
			'a' <= it && it <= 'z'
		}.joinToString(separator = "")
		if(s == "no"){
			cnt++
			if(cnt > 3){
				println("normal")
				return
			}
			continue
		}
		else{
			if(s in listOf("worse", "terrible", "noway", "donteven", "areyouserious", "godieinahole")){
				println("grumpy")
			}
			else println("normal")
			return
		}
	}
}
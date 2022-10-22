package main

import (
	"fmt"
	//"github.com/mactsouk/go/simpleGitHub"
)

func main() {
	var a int
	fmt.Scanf("%d", &a)
	if a % 2 == 0 && a != 2 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
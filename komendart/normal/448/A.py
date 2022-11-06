def main():
    a = sum(int(i) for i in input().split())
    b = sum(int(i) for i in input().split())
    n = int(input())
    
    if (a + 4) // 5 + (b + 9) // 10 > n:
        print("NO")
    else:
        print("YES")


main()
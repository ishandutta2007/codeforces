def main():
    n = int(input())
    arr = input().split()
    
    one = arr.count("100")
    two = arr.count("200")
    
    if one % 2 == 1 or two % 2 == 1 and one == 0:
        print("NO")
    else:
        print("YES")

main()
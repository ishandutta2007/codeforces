def main():
    x, y = [int(i) for i in input().split()]
    n = int(input())
    
    result = [x, y, y - x, -x, -y, x - y][(n - 1) % 6]
    
    print(result % 1000000007)


main()
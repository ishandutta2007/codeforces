def main():
    n = int(input())
    min1, max1 = [int(i) for i in input().split()]
    min2, max2 = [int(i) for i in input().split()]
    min3, max3 = [int(i) for i in input().split()]
    
    for x in range(min(n - 1, max1), min1 - 1, -1):
        if min3 <= n - x - max2 <= max3:
            print(x, max2, n - x - max2)
            return
        if min2 <= n - x - min3 <= max2:
            print(x, n - x - min3, min3)
            return 
    
    
main()
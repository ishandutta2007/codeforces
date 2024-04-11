def main():
    n = int(input())
    a = [int(i) for i in input().split()]
    
    a.sort()
    
    if len(a) == 1:
        print(a[0])
    else:
        a[-2] += a[-1]; a.pop()
        result = 0
        for i in range(n - 1):
            result += a[i] * (i + 2)
        print(result)


main()
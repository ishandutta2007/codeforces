def main():
    n, k = [int(i) for i in input().split()]
    
    result = -float("inf")
    for i in range(n):
        f, t = [int(i) for i in input().split()]
        result = max(result, f - max(0, t - k))
    
    print(result)

main()
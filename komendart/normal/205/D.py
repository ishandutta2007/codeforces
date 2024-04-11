def main():
    n = int(input())
    d = {}
    
    for i in range(n):
        a, b = [int(i) for i in input().split()]
        
        if a == b:
            if a not in d:
                d[a] = [0, 0]
            d[a][0] += 1
        else:
            if a not in d:
                d[a] = [0, 0]
            d[a][0] += 1
            if b not in d:
                d[b] = [0, 0]
            d[b][1] += 1
    
    result = float("inf")
    half = (n + 1) // 2
    for a, b in d.values():
        if a + b >= half:
            result = min(max(0, half - a), result)
    if result == float("inf"):
        print(-1)
    else:
        print(result)

main()
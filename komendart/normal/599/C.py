def main():    
    n = int(input())
    a = [int(i) for i in input().split()]
    b = sorted(a)
    
    diff = 0
    d = {}
    result = 0
    maxi = 0
    for i in range(n):
        if a[i] not in d: d[a[i]] = 0
        if b[i] not in d: d[b[i]] = 0
        if d[a[i]] == 0: diff += 1
        d[a[i]] += 1
        if d[a[i]] == 0: diff -= 1
        if d[b[i]] == 0: diff += 1
        d[b[i]] -= 1
        if d[b[i]] == 0: diff -= 1    
        if diff == 0: result += 1
    
    print(result)
    

main()
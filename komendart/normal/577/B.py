def main():
    n, m = [int(i) for i in input().split()]
    if n > m:
        print("YES")
        return
    a = [int(i) % m for i in input().split()]
    d = [False] * m
    for i in a:
        next = d[:]
        for j in range(m):
            k = j + i
            if k >= m: k -= m
            next[k] = d[k] or d[j]
        d = next
        d[i] = True
    if d[0]:
        print("YES")
    else:
        print("NO")
    
    
    
main()
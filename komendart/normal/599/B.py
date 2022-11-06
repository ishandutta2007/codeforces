def main():
    n, m = [int(i) for i in input().split()]
    f = [-1] + [int(i) for i in input().split()]
    b = [-1] + [int(i) for i in input().split()]
    
    d = [-1] * (n + 1)
    cnt = [0] * (n + 1)
    for i in range(1, n + 1):
        cnt[f[i]] += 1
        d[f[i]] = i
   
    a = [-1] * (m + 1)
    for i in range(1, m + 1):
        a[i] = d[b[i]]
        if d[b[i]] == -1:
            print("Impossible")
            return
    for i in range(1, m + 1):
        if cnt[b[i]] > 1:
            print("Ambiguity")
            return
    print("Possible")
    print(' '.join(str(i) for i in a[1:]))
    

main()
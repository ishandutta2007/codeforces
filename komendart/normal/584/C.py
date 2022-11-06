def main():
    import sys
    
    n, t, s1, s2 = sys.stdin.read().split()
    n, t = int(n), int(t)
    
    result = [-1] * n
    rest = n - t
    for i in range(n):
        if rest == 0: break
        if s1[i] == s2[i]:
            result[i] = s1[i]
            rest -= 1
    k = rest
    for i in range(n):
        if k == 0: break
        if result[i] == -1:
            result[i] = s1[i]
            k -= 1
    k = rest
    for i in range(n):
        if k == 0: break
        if result[i] == -1:
            result[i] = s2[i]
            k -= 1    
    if k > 0:
        print(-1)
        return
    for i in range(n):
        if result[i] == -1:
            for j in range(ord('a'), ord('a') + 4):
                if chr(j) != s1[i] and chr(j) != s2[i]:
                    result[i] = chr(j)
                    break
    
    sys.stdout.write(''.join(result))
    
main()
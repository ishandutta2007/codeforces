def main():
    import sys
    data = [int(i) for i in sys.stdin.read().split()]
    data.reverse()
    
    n, q = data.pop(), data.pop()
    arr = [data.pop() for i in range(n)]
    arr.sort()
    
    S = [0 for i in range(n + 1)]
    for i in range(q):
        l, r = data.pop(), data.pop()
        S[r] += 1
        S[l - 1] -= 1
    
    d = [0 for i in range(n)]
    count = 0
    for i in reversed(range(n)):
        count += S[i + 1]
        d[i] = count
    d.sort()
    
    result = 0
    for i in range(n):
        result += d[i] * arr[i]
    
    print(result)

main()
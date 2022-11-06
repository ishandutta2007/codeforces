def main():
    import sys
    
    tokens = [int(i) for i in sys.stdin.read().split()]
    tokens.reverse()
    
    n, k, p = [tokens.pop() for i in range(3)]
    a = [tokens.pop() for i in range(n)]
    odd = [i for i in a if i & 1]
    even = [i for i in a if i & 1 == 0]
    
    if len(odd) < k - p or (len(odd) - (k - p)) % 2 == 1 or len(odd) + 2 * len(even) < k + p:
        print("NO")
        return
    
    result = []
    for i in range(k - p):
        result.append([odd.pop()])
    
    while len(result) < k and odd:
        result.append([odd.pop(), odd.pop()])
    while len(result) < k and even:
        result.append([even.pop()])
    
    if len(result) < k:
        print("NO")
        return
    
    result[-1].extend(odd)
    result[-1].extend(even)
    
    print("YES")
    print('\n'.join(' '.join(map(str, [len(i)] + i)) for i in result))
    
    

main()
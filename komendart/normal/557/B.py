def main():
    import sys
    
    tokens = [int(i) for i in sys.stdin.read().split()]
    tokens.reverse()
    
    n, w = tokens.pop(), tokens.pop()
    a = [tokens.pop() for i in range(2 * n)]
    a.sort()
    
    print(min(w, min(a[0], a[n] / 2) * 3 * n))
    
main()
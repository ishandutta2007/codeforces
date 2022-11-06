def main():
    import sys
    from collections import defaultdict
    
    tokens = [int(i) for i in sys.stdin.read().split()]
    tokens.reverse()
    
    n, k = tokens.pop(), tokens.pop()
    
    d1 = defaultdict(int)
    d2 = defaultdict(int)
    result = 0
    for i in tokens:
        result += d2[i * k]
        d2[i] += d1[i * k]
        d1[i] += 1
    
    print(result)
    
    
main()
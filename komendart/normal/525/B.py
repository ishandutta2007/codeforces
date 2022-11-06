def main():
    import sys
    
    s = sys.stdin.readline().strip()
    m = int(sys.stdin.readline())
    
    d = [0 for i in range(len(s) + 1)]
    for i in sys.stdin.readline().split():
        d[int(i)] ^= 1
    
    rev = 0
    result = [i for i in s]
    for i in range(1, len(s) // 2 + 1):
        rev ^= d[i]
        if rev:
            result[i - 1], result[len(s) - i] = result[len(s) - i], result[i - 1]
    
    print(''.join(result))
        
    
    
main()
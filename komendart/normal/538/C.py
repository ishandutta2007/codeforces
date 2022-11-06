def main():
    import sys
    tokens = [int(i) for i in sys.stdin.read().split()]
    tokens.reverse()
    
    result = 0
    n, m = tokens.pop(), tokens.pop()
    pd, ph = 0, 0
    for i in range(m):
        d, h = tokens.pop(), tokens.pop()
        if i == 0:
            result = h + (d - 1)
        else:
            delta_d = d - pd
            delta_h = abs(h - ph)
            if delta_h > delta_d:
                print("IMPOSSIBLE")
                return
            else:
                result = max(result, max(h, ph) + (delta_d - delta_h) // 2)
        if i == m - 1:
            result = max(result, h + (n - d))
        pd, ph = d, h
    print(result)
    
main()
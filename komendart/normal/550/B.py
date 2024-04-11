def main():
    import sys
    n, l, r, x, *c = [int(i) for i in sys.stdin.read().split()]
    result = 0
    for mask in range(1 << n):
        number = 0
        minimal = float("inf")
        maximal = -float("inf")
        s = 0
        for i in range(n):
            if mask & (1 << i):
                s += c[i]
                number += 1
                minimal = min(minimal, c[i])
                maximal = max(maximal, c[i])
        if number >= 2 and l <= s <= r and maximal - minimal >= x:
            result += 1
    print(result)
    
    
main()
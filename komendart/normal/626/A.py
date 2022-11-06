def main():
    from collections import defaultdict
    
    d = defaultdict(int)
    d[(0, 0)] += 1
    n = int(input())
    s = input()
    x = y = 0
    res = 0
    for i in s:
        if i == 'U': x += 1
        elif i == 'D': x -= 1
        elif i == 'L': y += 1
        else: y -= 1
        res += d[(x, y)]
        d[(x, y)] += 1
    
    print(res)
    
    
main()
def main():
    from itertools import combinations
    from functools import reduce
    from random import randrange
    
    l, r, k = [int(i) for i in input().split()]
    
    if r - l < 4:
        f = float("inf")
        result = None
        numbers = list(range(l, r + 1))
        for mask in range(1, 1 << (r - l + 1)):
            tmp = [numbers[i] for i in range(r - l + 1) if mask & (1 << i)]
            if len(tmp) <= k and reduce(lambda x, y: x ^ y, tmp) < f:
                f = reduce(lambda x, y: x ^ y, tmp)
                result = tmp
    elif k >= 4:
        a = l + l % 2
        f = 0
        result = [a, a + 1, a + 2, a + 3]
    elif k == 1:
        f = l
        result = [l]
    elif k == 2:
        a = l + l % 2
        f = 1
        result = [a, a + 1]
    elif k == 3:
        a = l + l % 2
        f = 1
        result = [a, a + 1]
        for a in range(l, min(r + 1, l + 400)):
            for b in range(max(l, r - 400), r + 1):
                if l <= a ^ b <= r:
                    f = 0
                    result = [a, b, a ^ b]
                    break
        for i in range(100000):
            a = randrange(l, r + 1)
            b = randrange(l, r + 1)
            if l <= a ^ b <= r:
                f = 0
                result = [a, b, a ^ b]
                break
        
        
    print(f)
    print(len(result))
    print(' '.join(str(i) for i in sorted(result)))


main()
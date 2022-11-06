def main():
    from collections import defaultdict
    import sys
    
    strings = sys.stdin.read().split('\n')
    strings.reverse()
    
    f = defaultdict(lambda: defaultdict(int))
    n = int(strings.pop())
    
    for i in range(n):
        s = strings.pop().replace('(', ' ').replace(')', ' ').replace(',', ' ')
        _, name, *args = s.split()
        f[name][tuple(args)] += 1
    
    m = int(strings.pop())
    variables = dict(reversed(strings.pop().split()) for j in range(m))
    
    result = []
    k = int(strings.pop())
    for i in range(k):
        s = strings.pop().replace('(', ' ').replace(')', ' ').replace(',', ' ')
        name, *args = s.split()
        
        count = 0
        args = [variables[i] for i in args]
        N = len(args)
        for mask in range(1 << N):
            tmp = tuple('T' if mask & (1 << i) else args[i] for i in range(N))
            count += f[name][tmp]
        result.append(str(count))
    
    print('\n'.join(result))

main()
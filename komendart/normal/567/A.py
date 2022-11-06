def main():
    import sys
    
    n, *a = [int(i) for i in sys.stdin.read().split()]
    
    result = []
    for i in range(n):
        maximal = max(a[i] - a[0], a[n - 1] - a[i])
        if i == 0: minimal = a[1] - a[0]
        elif i == n - 1: minimal = a[n - 1] - a[n - 2]
        else: minimal = min(a[i] - a[i - 1], a[i + 1] - a[i])
        result.append("{0} {1}".format(minimal, maximal))
    
    print('\n'.join(result))
    
    
main()
def main():
    n, m = [int(i) for i in input().split()]
    
    colors = [0 for i in range(n + 1)]
    for i in range(m):
        arr = [int(i) for i in input().split()]
        early = colors[arr[0]] or colors[arr[1]] or colors[arr[2]]
        l = [1, 2, 3]
        if early: l.remove(early)
        for i in arr:
            if colors[i] == 0:
                colors[i] = l.pop()
    
    print(' '.join(str(colors[i]) for i in range(1, n + 1)))
    
main()
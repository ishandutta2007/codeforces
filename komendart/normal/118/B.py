def main():
    n = int(input())
    
    f = lambda y, x: n - (abs(n - y) + abs(n - x))
    for i in range(2 * n + 1):
        for j in range(2 * n + 1):
            t = f(i, j)
            if t < 0:
                print(' ', end=' ')
            elif t == 0 and j >= n:
                print(0, end='')
                break
            else:
                print(t, end=' ')
        print()

main()
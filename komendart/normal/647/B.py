def main():
    import sys
    input = sys.stdin.readline
    n, m = [int(i) for i in input().split()]
    x1 = n - 1
    x2 = 0
    y1 = m - 1
    y2 = 0
    for i in range(n):
        s = input()
        for j in range(m):
            if s[j] == '*':
                x1 = min(x1, i)
                x2 = max(x2, i)
                y1 = min(y1, j)
                y2 = max(y2, j)
    print(max(x2 - x1, y2 - y1) + 1)

main()
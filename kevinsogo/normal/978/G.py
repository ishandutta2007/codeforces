def solve():
    n, m = map(int, input().split())
    deed = [0]*n
    exams = []
    for i in range(m):
        s, d, c = map(int, input().split())
        s -= 1; d -= 1
        if deed[d]: return [-1]
        deed[d] = m + 1
        exams.append((d, s, c, i + 1))

    for d, s, c, idx in sorted(exams):
        for i in range(s, d):
            if deed[i] == 0:
                deed[i] = idx
                c -= 1
                if c == 0: break
        else:
            return [-1]

    return deed


print(*solve())
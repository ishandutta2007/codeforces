def solve(k, grid):
    seek = *range(2*k + 2), *range(4*k + 1, 2*k + 1, -1)
    flat = [seek[v] for v in grid[0] + grid[1][::-1] if v]

    m = {
        'L': 'l'*2*k + 'u' + 'r'*2*k + 'd',
        'R': 'u' + 'l'*2*k + 'd' + 'r'*2*k,
        'C': 'l'*k + 'u' + 'r'*k + 'd',
        'D': 'CC' + 'R'*(2*k + 1) + 'CC' + 'R'*(2*k + 2),
        'F': 'R'*(k - 1) + 'DD' + 'R'*(2*k + 1) + 'D' + 'L'*2*k + 'DD' + 'L'*k,
        'G': 'FF',
    }

    [(i, j)] = [(i, j) for i in range(2) for j in range(2*k + 1) if grid[i][j] == 0]
    st = 'r'*(2*k - j) + 'd'*(1 - i)

    for v in range(2, 4*k + 2):
        ct = flat.index(v)

        if ct >= 2:
            st += 'L'*(ct - 2) + 'GR'*(ct - 2) + 'G'
            flat = flat[ct - 1: ct + 1] + flat[:ct - 1] + flat[ct + 1:]

        if ct >= 1:
            st += 'G'
            flat = flat[1:3] + flat[:1] + flat[3:]

        st += 'L'
        flat = flat[1:] + flat[:1]
        
    if flat[0] == 1: return st, m

def main():
    def get_line():
        return [0 if x == 'E' else int(x) for x in input().split()]

    for cas in range(int(input())):
        res = solve(int(input()), [get_line() for i in range(2)])
        if res is None:
            print('SURGERY FAILED')
        else:
            print('SURGERY COMPLETE')
            st, m = res
            print(st)
            for shortcut in m.items(): print(*shortcut)
            print('DONE')

main()
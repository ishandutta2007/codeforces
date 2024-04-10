def read_numbers():
    return list(map(int, input().split()))


if __name__ == '__main__':
    n, m = read_numbers()
    numbers = read_numbers()

    numbers.sort()
    best = numbers[-1] - numbers[0]
    for i in range(len(numbers) - n + 1):
        if numbers[i + n - 1] - numbers[i] < best:
            best = numbers[i + n - 1] - numbers[i]

    print(best)